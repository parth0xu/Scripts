# **update.sh - System Update & Maintenance Script**

## **📌 Overview**
`update.sh` is a simple Bash script designed to **automate system updates, clean unnecessary files, and check system health** on Linux-based systems.

---

## **📌 How to Use**

### **1️⃣ Grant Execute Permission**
```bash
chmod +x update.sh
```

### **2️⃣ Run the Script**
```bash
sudo ./update.sh
```
✔ This will **update**, **clean**, and **check system health** automatically.

---

## **📌 Automate with Cron (Optional)**
To run this script automatically **every Sunday at 2 AM**, type:
```bash
crontab -e
```
Then add this line at the end:
```bash
0 2 * * 7 /path/to/update.sh
```

---

## **📌 Requirements**
🔹 Linux System (Ubuntu, Debian, etc.)  
🔹 Root/Sudo Access  

---


# **file_details.sh - File Information Script**

## **📌 Overview**
`file_details.sh` is a Bash script that provides detailed information about a specified file, including:
- File owner
- File size
- Creation date & time
- File type
- Read, write, and execute permissions

---

## **📌 How to Use**

### **1️⃣ Clone the Repository**
```bash
git clone https://github.com/parth0xu/Scripts.git
cd Scripts
```

### **2️⃣ Grant Execute Permission**
```bash
sudo chmod +x file_details.sh
```

### **3️⃣ Run the Script**
```bash
./file_details.sh filename
```
📌 Replace `filename` with the actual file you want to check.

---

## **📌 Example Usage**
```bash
./file_details.sh myfile.txt
```
**Example Output:**
```
File Name: myfile.txt

Owner: user
Size: 1024 bytes
This file was created on Mar 25 at 12:30
File Type: myfile.txt: ASCII text

Permissions:
Readable=TRUE
WRITABLE=TRUE
EXECUTABLE=FALSE
```

---

## **📌 Requirements**
🔹 Linux System (Ubuntu, Debian, etc.)  
🔹 Bash Shell  

---

## **📌 Author**
📌 Created by **Parth Dabgar**  
📧 Contact: dabgarparth12@gmail.com  

---

