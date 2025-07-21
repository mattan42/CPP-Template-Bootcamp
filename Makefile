
BUILD_DIRECTORY=build

.PHONY: stage_1
stage_1:
	cmake -B $(BUILD_DIRECTORY) .
	make -C $(BUILD_DIRECTORY) stage_1

.PHONY: stage_1_solution
stage_1_solution:
	cmake -B $(BUILD_DIRECTORY) .
	make -C $(BUILD_DIRECTORY) stage_1_solution
