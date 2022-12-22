# Build Stage
FROM --platform=linux/amd64 ubuntu:22.04 as builder

## Install build dependencies.
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y clang

## Add source code to the build stage.
ADD . /mjson
WORKDIR /mjson/mayhem
## Build
RUN clang -fsanitize=fuzzer fuzz_parse.c ../src/mjson.c -I ../src/ -o fuzz_parse

# Package Stage
FROM --platform=linux/amd64 ubuntu:22.04
COPY --from=builder /mjson/mayhem/fuzz_parse /fuzz_parse

## Set up fuzzing!
ENTRYPOINT []
CMD /fuzz_parse
