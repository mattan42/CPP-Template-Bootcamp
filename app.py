import streamlit as st
from streamlit_ace import st_ace
from pathlib import Path
import pandas as pd
import subprocess

REPO_ROOT_PATH = Path(__file__).parent


# Main Page
def main_page_run():
    st.markdown((REPO_ROOT_PATH / "README.md").read_text(), unsafe_allow_html=True)


# Stage 1 Page
def stage_problem_page_run(stage_number: int):
    stage_directory_path = REPO_ROOT_PATH / "Stages" / str(stage_number)

    left_column, right_column = st.columns(2)

    left_column.markdown((stage_directory_path / "Problem" / "README.md").read_text())
    with right_column.expander(label="Tests File", expanded=True):
        st.code((stage_directory_path / "main.cpp").read_text(), language="cpp")

    st.divider()

    st.title("Try to Solve!")

    solution_attempt_hpp_file = (
        stage_directory_path / "Problem" / "solution.hpp"
    ).read_text()

    submitted_code = st_ace(
        value=solution_attempt_hpp_file,
        theme="twilight",
        language="c_cpp",
        key=f"stage_problem_page_run_{str(stage_number)}_code_editor",
    )

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


# Pages
main_page = st.Page(main_page_run, title="Main Page", icon="ℹ️")
stage_1_problem_page = st.Page(
    lambda: stage_problem_page_run(1),
    url_path="stage_1_problem",
    title="Stage 1 Problem",
    icon="🤔",
)
stage_2_problem_page = st.Page(
    lambda: stage_problem_page_run(2),
    url_path="stage_2_problem",
    title="Stage 2 Problem",
    icon="🤔",
)

# App
pg = st.navigation([main_page, stage_1_problem_page, stage_2_problem_page])
st.set_page_config(page_title="C++ Template Bootcamp", page_icon="🧑‍💻", layout="wide")
pg.run()
