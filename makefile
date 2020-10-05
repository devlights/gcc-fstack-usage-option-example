CC = gcc
CFLAGS = -g -Wall -Wextra -fstack-usage

EXEC_TARGET = fstack-check-example

usage:
	@echo '--------------------------------------------------------'
	@echo 'Avaiable tasks:'
	@echo '  - not-stack-size-over'
	@echo '    - compile and run program which not over stack size'
	@echo '  - stack-size-over'
	@echo '    - compile and run program which over stack size'
	@echo '  - clean'
	@echo '    - clean up (module, su files, core files)'
	@echo '  - view-su'
	@echo '    - view generated su files'
	@echo '--------------------------------------------------------'

not-stack-size-over: _compile_not_over _run

stack-size-over: _compile_over _run

_compile_not_over:
	@$(CC) $(CFLAGS) -USTACKSIZE_OVER -o $(EXEC_TARGET) *.c

_compile_over:
	@$(CC) $(CFLAGS) -DSTACKSIZE_OVER -o $(EXEC_TARGET) *.c

_run:
	@./$(EXEC_TARGET)

clean:
	@$(RM) ./$(EXEC_TARGET)
	@$(RM) ./core*
	@$(RM) ./*.su

view-su: _compile_not_over
	@find . -name "*.su" -type f | xargs cat | awk -F" " '{printf("%-50s\t%d\t%s\n", $$1, $$2, $$3)}'
