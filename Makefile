
BUILD_DIRECTORY=build

.PHONY: stage_1
stage_1:
	cmake -B $(BUILD_DIRECTORY) .
	make -C $(BUILD_DIRECTORY) stage_1

.PHONY: stage_1_solution
stage_1_solution:
	cmake -B $(BUILD_DIRECTORY) .
	make -C $(BUILD_DIRECTORY) stage_1_solution

.PHONY: stage_2
stage_2:
	cmake -B $(BUILD_DIRECTORY) .
	make -C $(BUILD_DIRECTORY) stage_2

.PHONY: stage_2_solution
stage_2_solution:
	cmake -B $(BUILD_DIRECTORY) .
	make -C $(BUILD_DIRECTORY) stage_2_solution
