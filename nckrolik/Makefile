.PHONY: step1 step2 clean

step1:
	@echo "step 1..."
	cd ./Step1 && g++ -std=c++11 *.cpp -o parser
	cd ./Step1 && for file in ./ParserInputTest/*; do ./parser $$file; done
	cp -r ./Step1/ParserBinaryOut/* ./Step2/VMBinaryInput
	
	@echo "step1 done"
step2: step1
	@echo "step 2..."
	cd ./Step2 && g++ -std=c++11 *.cpp -o vm 
	cd ./Step2 && for file in ./VMBinaryInput/*; do ./vm $$file; done
clean:
	@echo "cleaning..."


