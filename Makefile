
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

.PHONY: stage_3
stage_3:
	cmake -B $(BUILD_DIRECTORY) .
	make -C $(BUILD_DIRECTORY) stage_3

.PHONY: stage_3_solution
stage_3_solution:
	cmake -B $(BUILD_DIRECTORY) .
	make -C $(BUILD_DIRECTORY) stage_3_solution

.PHONY: stage_4
stage_4:
	cmake -B $(BUILD_DIRECTORY) .
	make -C $(BUILD_DIRECTORY) stage_4

.PHONY: stage_4_solution
stage_4_solution:
	cmake -B $(BUILD_DIRECTORY) .
	make -C $(BUILD_DIRECTORY) stage_4_solution
