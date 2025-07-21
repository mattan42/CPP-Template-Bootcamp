import streamlit as st
from pathlib import Path

# Main Page
def main_page():
    st.markdown((Path.cwd()/"README.md").read_text(), unsafe_allow_html=True)

# Pages
main_page = st.Page(main_page, title="Main Page", icon="ℹ️")
stage_1 = st.Page("Stages/1/stage.py", title="Stage 1")

# App
pages = [main_page, stage_1]
pg = st.navigation(pages)
st.set_page_config(page_title="C++ Template Bootcamp", page_icon="🧑‍💻")
pg.run()