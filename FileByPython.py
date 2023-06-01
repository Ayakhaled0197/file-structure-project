def write_records():
      with open ('grocerypy.txt','a') as file:
             c="YES"
             while c == "YES":
                  item = input("Enter Item  : ")
                  quantity = input("Enter the quantity of the item : ")
                  price = input("Enter Price of the item : ")  
                  file.write(item + "\t" + price + "\t" +quantity + "\n")
                  c = input("do u want YES or NO: ")      
             print("the process have completed")
 
def read_records():
      print("item\tprice\tquantity"  )
      print("------------------------------")
      with open ('grocerypy.txt','r') as file:
            for line in file:   # print(file.read())
                  print(line , end ="")  
 
 
def search_records():
      item = input("search for item u want ")
      with open ("grocerypy.txt", "r") as file:
            for line in file : 
                  l =line.split("\t")  # l = [item , quantity , price]
                  if l[0] == item :
                        print("item\tprice\tquantity"  )
                        print("------------------------------")
                        print(line)
                        return 
      print("item not found in the grocery")
 
def delete_records():
       import os
       flag = False
       item = input("search for item u want to delete ")
       file = open ("grocerypy.txt", "r") 
       temp =open ("temperory.txt", "w") 
       for line in file : 
                  l =line.split("\t")  # l = [item , quantity , price]
                  if l[0] == item :
                        flag = True
                  else:
                        temp.write(line)
 
       file.close()
       temp.close()
       os.remove("grocerypy.txt")
       os.rename("temperory.txt","grocerypy.txt")
       if not flag:
              print("record arenot found")
 
def update_records():
       import os
       item = input("search for item u want to update ")
       file = open ("grocerypy.txt", "r") 
       temp = open ("temperory.txt", "w") 
       for line in file : 
                  l =line.split("\t")  # l = [item , quantity , price]
                  if l[0] == item :
                         items = input("enter ur new item " )
                         temp.write(items + "\t" + l[1] + "\t" +l[2]   )
                  else:
                     temp.write(line)
 
       file.close()
       temp.close()
       os.remove("grocerypy.txt")
       os.rename("temperory.txt","grocerypy.txt")
 
 
 
print("grocery items")
print("----------")
print("(1) for reading records")
print("(2) for writting records")
print("(3) for searching ")
print("(4) for updating records")
print("(5) for deleting")
 
cases = input(" enter the operation u want to make ")
match cases :
       case "1" :
              read_records()
       case "2" : 
              write_records()
       case "3" : 
              search_records()
       case "4" : 
              update_records()
       case "5" : 
              delete_records()

