#!/bin/bash
task="pathpathpathpath"
memory=131072
stack_size=131072
ulimit -v "${memory}"
ulimit -s "${stack_size}"
"./${task}"
