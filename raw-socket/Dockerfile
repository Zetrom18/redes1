FROM gcc
USER root
WORKDIR /
RUN apt-get update
RUN apt-get install net-tools
RUN ifconfig
COPY . .
RUN make
RUN ls
CMD ["./teste", "m"]
