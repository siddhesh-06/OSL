choice=0
echo -e "Name\t\tRoll"

while  [ $choice -ne 6 ]
do
echo -e "\n============ Menu ============="
echo "1. Create address book"
echo "2. View address book"
echo "3. Insert record"
echo "4. Delete record"
echo "5. Modify record"
echo "6. Exit"
echo ""
read -p "Enter your choice: " choice

case $choice in
    1)
        read -p "Enter name of address book: " address_book
        if [ -f $address_book-address_book.txt ]
        then 
            echo -e "\nError: Alredy exist"
        else
            touch "$address_book-address_book.txt"
            echo "Book Done"
        fi
        ;;
    2)  echo -e "\nAdress book"
        echo -e "\nName\t\tPhone\t\tCity\n"
        cat file1-address_book.txt
        # while read line
        # do  
        #     echo -e "$line"
        # done < file1-address_book.txt
        ;;
    3)  echo -e "\n Insert Values"
        read -p "Name " name
        read -p "Phone " phone
        read -p "City " city
        echo -e "$name\t\t$phone\t\t$city" >> file1-address_book.txt
        echo -e "Inserted"
        ;;
    4)  
        echo -e "\nEnter following details"
        read -p "Name: " name
        read -p "Phone: " phone

        sed -i "/$name.*$phone/d" file1-address_book.txt && echo -e "Delete success" || echo -e "\n record not found"
        ;;
    5)  echo -e "Enter old details"
        read -p "Name: " oldname
        read -p "Phone: " oldphone

        echo -e "Enter new details"
        read -p "Name: " newname
        read -p "Phone: " newphone
        read -p "City: " newcity

        # checking
        sed -i "s/$oldname.*$oldphone.*/$newname\t\t$newphone\t\t$newcity/" file1-address_book.txt
        ;;
    6)
		echo "Thank You !!"
		;;
	*)
		echo "Invalid value"
		;;
    esac

done
