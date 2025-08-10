import streamlit as st
from streamlit_ace import st_ace
from pathlib import Path
import pandas as pd
import subprocess

REPO_ROOT_PATH = Path(__file__).parent


# Main Page
def main_page_run():
    st.markdown((REPO_ROOT_PATH / "README.md").read_text(), unsafe_allow_html=True)


def stage_problem_page_run(stage_number: int):
    stage_directory_path = REPO_ROOT_PATH / "Stages" / str(stage_number)

    st.markdown((stage_directory_path / "Problem" / "README.md").read_text())
    st.divider()

    st.title("Try to Solve!")

    solution_attempt_hpp_file = (
        stage_directory_path / "Problem" / "solution.hpp"
    ).read_text()
    
    left_column, right_column = st.columns(2)

    with left_column:
        submitted_code = st_ace(
            value=solution_attempt_hpp_file,
            theme="twilight",
            language="c_cpp",
            key=f"stage_problem_page_run_{str(stage_number)}_code_editor",
        )
    with right_column.expander(label="Tests File", expanded=False):
        st.code((stage_directory_path / "main.cpp").read_text(), language="cpp")

    (stage_directory_path / "Problem" / "solution.hpp").write_text(submitted_code)

    compile_and_run_button = st.button(
        "Compile and Run",
        key=f"stage_problem_page_run_{str(stage_number)}_compile_and_run_button",
    )

    console_output_widget = st.empty()

    if compile_and_run_button:
        console_output = []
        result = subprocess.Popen(
            ["make", "stage_1"], stdout=subprocess.PIPE, stderr=subprocess.PIPE
        )

        def read_output():
            for readline in [result.stdout.readline, result.stderr.readline]:
                line = readline()
                if line != b"":
                    return line

            return b""

        for line in iter(read_output, b""):
            console_output.append(line.decode("utf-8"))
            console_output_widget.code(
                "".join(console_output), line_numbers=True, language=None
            )

def create_streamlit_problem_page(stage_number: int, icon="🤔", title=None) -> st.Page:
    if not title:
        title = f"Stage {stage_number}"
    else:
        title = f"Stage {stage_number}: {title}"
    

    return st.Page(
        lambda: stage_problem_page_run(stage_number),
        url_path=f"stage_{stage_number}_problem",
        title=title,
        icon=icon,
    )

# App
pg = st.navigation([st.Page(main_page_run, title="Main Page", icon="ℹ️"),
                    create_streamlit_problem_page(stage_number=1),
                    create_streamlit_problem_page(stage_number=2, icon="🦆", title="Ducks"),
                    create_streamlit_problem_page(stage_number=3, icon="💯", title="Full Specializations"),
                    create_streamlit_problem_page(stage_number=4, icon="🤏", title="Partial Specializations"),
])
st.set_page_config(page_title="C++ Template Bootcamp", page_icon="🧑‍💻", layout="wide")
pg.run()
