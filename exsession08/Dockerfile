FROM ubuntu:18.04

RUN apt-get update &&  \
    apt upgrade -y && \
	apt-get install -y -q \
        apt-utils \
        libpng-dev \
        pkg-config \
        libfreetype6-dev \
		g++ \
		make \
		python3-pip

RUN	pip3 install \
        --upgrade pip \
        tk \
		numpy \
        matplotlib

RUN DEBIAN_FRONTEND=noninteractive apt-get install -q -y --no-install-recommends \
		python3-tk

COPY ./poisson_serial /poisson_serial
WORKDIR ./poisson_serial
RUN make
CMD ./main && \
	cd output && \
	python3 plot.py