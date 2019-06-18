FROM gcc
USER root
WORKDIR /app
RUN apt-get update
RUN apt-get install net-tools
RUN ifconfig
COPY . .
RUN make clean
RUN make slave
RUN make master