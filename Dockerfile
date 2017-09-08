# To build use:
# docker build -t orian/cppenv:v1 .
FROM ubuntu:17.04
MAINTAINER Chase Willden <chase.willden@gmail.com>

LABEL description="A linux C++ build environment."

RUN apt-get update && apt-get install -y \
  build-essential \
  nasm \
  genisoimage \
  qemu-system-i386

ENV LD_LIBRARY_PATH=/libs
ENV CPLUS_INCLUDE_PATH=/libs/include

RUN mkdir /src
RUN mkdir /build
WORKDIR /build

ADD . /build

CMD ["/bin/bash"]