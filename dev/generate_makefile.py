#!/bin/python3

import click
from pathlib import Path
import jinja2

stage_makefile_target_template= jinja2.Environment(loader=jinja2.BaseLoader()).from_string("""
.PHONY: stage_{{stage_number}}
stage_{{stage_number}}:
	cmake -B $(BUILD_DIRECTORY) .
	make -C $(BUILD_DIRECTORY) stage_{{stage_number}}

.PHONY: stage_{{stage_number}}_solution
stage_{{stage_number}}_solution:
	cmake -B $(BUILD_DIRECTORY) .
	make -C $(BUILD_DIRECTORY) stage_{{stage_number}}_solution

""")

@click.command()
@click.argument("stage_count", type=int)
@click.option("--output", "-o", help="Directory path to output the makefile to.")
def main(stage_count, output=None):
    """STAGE_COUNT is how many stages are there."""
    makefile_content = """
BUILD_DIRECTORY=build
"""
    for stage_number in range(1, stage_count + 1):
        makefile_content += stage_makefile_target_template.render(stage_number=stage_number)
    
    if output is None:
        output = Path.cwd()
    else:
        output = Path(output)
        assert output.is_dir(), "Output path has to be a directory."
    
    with output.joinpath("Makefile").open("w") as output_file:
        output_file.write(makefile_content)



if __name__ == "__main__":
    main()
