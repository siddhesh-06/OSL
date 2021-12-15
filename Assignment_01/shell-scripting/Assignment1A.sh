# ! /usr/bin/bash

# VARIABLES
# NAME="SIDDHESH"
# echo "Hello ${NAME}"


# USER INPUT
#read -p "Enter your name: " NAME
#echo "Welcome $NAME"


# CONDITINAL STATEMENTS

## IF
#if [ "$NAME" == "SIDDHESH" ]; then
#    echo "Hii, Siddhesh"
#fi

##IF ELSE
# NAME="6"
# if [ "$NAME" -eq "6" ] 
# then
#    echo "Equal"
# else
#    echo "Not equal"
# fi

##ELIF
#if [ "$NAME" == "Goku" ]
#then 
#    echo "Hii Goku"
#elif [ "$NAME" == "Sid" ]
#then 
#    echo "Hey Sid"
#else
#    echo "Error"
#fi    


# OPERATORS FOR COMPARISONS

####
# val1 -eq val2 Returns true if values are equal 
# val1 -ne val2 Returns true if values are not-equal 
# val1 -gt val2 Returns true if val1 > val2
# val1 -ge val2 Returns true if val1 >= val2 
# val1 -lt val2 Returns true if val1 < val2 
# val1 -le val2 Returns true if val1 <= val2 
####



# FILE CONDITIONS

########
# -d file   True if the file is a directory
# -e file   True if the file exists (note that this is not particularly portable, thus -f is generally used)
# -f file   True if the provided string is a file
# -g file   True if the group id is set on a file
# -r file   True if the file is readable
# -s file   True if the file has a non-zero size
# -u    True if the user id is set on a file
# -w    True if the file is writable
# -x    True if the file is an executable
########

# FILE="file.txt"
# if [ -f $FILE ]
# then 
#     echo "File exist"
# else 
#     echo "File does not exist" 
# fi


# CASE STATEMENT
# read -p "Are you 18+ ? Y/N" ANSWER
# case $ANSWER in 
#     [yY] | [yY][eE][sS])
#         echo "You can have a drink :)"
#         ;;
#     [nN] | [nN][oO])
#         echo "Sorry u can't drink :("
#         ;;
#     *)
#         echo "Please enter y/yes or n/no"
#         ;;
# esac     


# SIMPLE FOR LOOP
# NAMES="Sid Abhiraj Sanket Om"
# for NAME in $NAMES
#     do 
#         echo "Hii $NAME"
# done     

# FILES=$(ls *.txt )
# NEW="new"
# for FILE in $FILES
#     do  
#         echo "Renaming $FIlE to new-$FILE"
#         mv $FILE $NEW-$FILE
# done


# WHILE LOOP
# LINE=1
# while read -r CURRENT_LINE
#     do 
#         echo "$LINE: $CURRENT_LINE"
#         ((LINE++))
# done < "./new-1.txt" 

INT=4
COUNT=0
while ($INT -eq "4")
    do 
        echo "Good Morning"
        ((COUNT++))
done        


# FUNCTIONS
# function sayHii(){
#     echo "Hiii"
# }

# sayHii

# PARAMS
# function greet(){
#     echo "My name is $1 and I'm $2 years old"
# }

# greet "Sid" "19"

# mkdir hello
# touch "hello/world.txt"
# echo "Hello world" >> "hello/world.txt"
# echo "Created hello/world.txt"