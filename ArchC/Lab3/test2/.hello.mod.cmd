cmd_/home/oda/repos/test2/hello.mod := printf '%s\n'   hello.o | awk '!x[$$0]++ { print("/home/oda/repos/test2/"$$0) }' > /home/oda/repos/test2/hello.mod
