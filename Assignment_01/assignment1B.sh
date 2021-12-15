choice=0

while [ $choice -ne 6 ]
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
			echo -e "\nError: Address Book already exist."
		else
			touch "$address_book-address_book.txt"
			echo -e "\nAddress book $address_book-address_book.txt created successfully\n"
		fi
		;;
	2)
		echo -e "\n========== Address Book =========="
		echo -e "\nName\t\tPhone\t\t\tCity\n"
		while read line
		do
			echo -e "$line"
		done < file3-address_book.txt
		;;
	3)
		echo -e "\n========== Insert new record ==========\n"
		read -p "Name: " name
		read -p "Phone: " phone
		read -p "City: " city
		echo -e "$name\t\t$phone\t\t$city" >> file3-address_book.txt
		echo -e "\nRecord inserted successfully !"
		;;
	4)
		echo -e "\nEnter following details\n"
		read -p "Name: " name
		read -p "Phone: " phone

		sed -i "/$name.*$phone/d" file3-address_book.txt && echo -e "\nDeleted successfully" || echo -e "\nRecord not found"
		;;
	5)
		echo -e "\nEnter old details\n"
		read -p "Name: " oldname
		read -p "Phone: " oldphone

		echo -e "\nEnter new details\n"
		read -p "New Name: " newname
		read -p "New Phone: " newphone
		read -p "New City: " newcity
		sed -i "s/$oldname.*$oldphone.*/$newname\t\t$newphone\t\t$newcity/" file3-address_book.txt
		;;
	6)
		echo "Thank You !!"
		;;
	*)
		echo "Invalid value"
		;;
	esac
done
