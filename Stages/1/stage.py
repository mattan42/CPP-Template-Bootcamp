import streamlit as st
import subprocess
from pathlib import Path

STAGE_DIRECTORY = Path(__file__).parent

problem_markdown_content = (STAGE_DIRECTORY / "problem/README.md").read_text()
test_file_content = (STAGE_DIRECTORY / "main.cpp").read_text()
solution_markdown_content = (STAGE_DIRECTORY / "solution/README.md").read_text()

def problem():
    with st.expander("Problem"):
        st.markdown(problem_markdown_content)

    with st.expander("Tests file"):
        st.code(test_file_content, language="cpp", line_numbers=True, wrap_lines=True)

    st.text_area("Submit a Solution (copy paste your code here!)")

problem_page = st.Page(problem)

selected = st.sidebar.selectbox("Sub-Page", ["Problem", "Solution"])
if selected == "Problem":
    st.switch_page(problem_page)

def compile_and_run():
    subprocess.run("make stage_1")
    pass

st.button(label="Compile & Run!", on_click=compile_and_run)

