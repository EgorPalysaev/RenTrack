FROM cleanstart/sqlite3:latest
FROM athenaos/base:latest
FROM gcc

COPY . /rentrack

WORKDIR /rentrack

RUN make

CMD [ "./app.exe" ]
