cmd_/home/oda/repos/Lab5/hello3.ko := ccache arm-eabi-ld -r -EL -z noexecstack -T ./scripts/module-common.lds -T ./arch/arm/kernel/module.lds  --build-id  -o /home/oda/repos/Lab5/hello3.ko /home/oda/repos/Lab5/hello3.o /home/oda/repos/Lab5/hello3.mod.o ;  true