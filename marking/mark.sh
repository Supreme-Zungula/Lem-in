FILES=$(find . -name "*.test")
BIN=../lem-in

for FILE in $FILES
do
	echo __________________________
	echo $FILE
	echo __________________________
	$BIN < $FILE
	echo
done
