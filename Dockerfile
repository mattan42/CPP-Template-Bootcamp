FROM ubuntu:22.04

RUN apt-get update && apt-get install -y cmake make python3 python3-pip

WORKDIR /app

COPY . .

RUN pip install -r dev/requirements.txt

CMD ["streamlit", "run", "app.py"]
