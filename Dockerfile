FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
  && apt-get install -y ssh \
    build-essential \
    gcc \
    gdb \
    clang \
    cmake \
    rsync \
    tar \
    python \
  && apt-get clean

ARG UID=1000
RUN useradd -m -u ${UID} -s /bin/bash builder
USER builder

