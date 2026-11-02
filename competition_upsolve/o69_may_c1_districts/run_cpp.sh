#!/bin/bash

task="districts"
memory=262144  # 256MiB
stack_size=262144  # 256MiB

ulimit -v "${memory}"
ulimit -s "${stack_size}"
"./${task}"
