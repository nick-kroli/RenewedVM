.PHONY: step1 step2 clean

step1:
	@echo "step 1..."
	cd ./Step1 && g++ -std=c++11 *.cpp -o parser
	cd ./Step1 && for file in ./ParserInputTest/*; do ./parser $$file; done
	cp -r ./Step1/ParserBinaryOut/* ./Step2/VMBinaryInput

step2:
	@echo "step 2..."
	cd ./Step2 && g++ -std=c++11 *.cpp -o vm 
	cd ./Step2 && for file in ./VMBinaryInput/*; do ./vm $$file; done

all: step1 step2

clean:
	@echo "cleaning..."
	rm -rf ./Step1/ParserBinaryOut/*
	rm -rf ./Step2/VMBinaryInput/*
	rm -rf ./Step2/VMBinaryOut/*
	rm -f ./Step1/parser
	rm -f ./Step2/vm

