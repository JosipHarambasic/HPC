FROM ubuntu:bionic

RUN apt-get update -q && \
	apt-get install -y -q \
		g++ \
		make \
		python-pip

RUN	pip install \
        tk \
		numpy \
        matplotlib

RUN DEBIAN_FRONTEND=noninteractive apt-get install -q -y --no-install-recommends \
		python-tk

COPY ./poisson_serial /poisson_serial
WORKDIR ./poisson_serial
RUN make
CMD ./main && \
	cd output && \
	python plot.py