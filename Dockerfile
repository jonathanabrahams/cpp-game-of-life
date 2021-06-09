FROM alpine:3.13

RUN apk add --update --no-cache \
    build-base cmake \
    git \
    make \
    musl-dev \
    curl \
    tar \
    linux-headers \
    openssh \
    gzip \
    ca-certificates \
    bash