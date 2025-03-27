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


# **Employee Data Collector**

## **📌 Overview**
This Bash script collects employee information and stores it in a CSV file (`employee_data.csv`). It prompts users for their **name, employee ID, department, and gender**, then verifies the information before saving it.

---

## **📌 Features**
✅ Collects employee details interactively  
✅ Stores data in a structured CSV format  
✅ Ensures user confirmation before saving  
✅ Simple and efficient to use  

---

## **📌 How to Use**

### **1️⃣ Clone the Repository**
```bash
git clone https://github.com/your-username/Scripts.git
cd Scripts
```

### **2️⃣ Grant Execute Permission**
```bash
chmod +x employee_data_collector.sh
```

### **3️⃣ Run the Script**
```bash
./employee_data_collector.sh
```
✔ The script will prompt you for input and save the details in `employee_data.csv`.

---

## **📌 Example Input & Output**
### **User Input:**
```
[+] Enter your name: John Doe
[+] Enter your employee ID: 12345
[+] Enter your department: IT
[+] Enter your gender: Male
Do you have given the correct information [y/n]: y
```

### **CSV Output (`employee_data.csv`):**
```
John Doe,12345,IT,Male
```

---

## **📌 Requirements**
🔹 Linux or macOS (Bash Shell)  
🔹 No additional dependencies  

---

# Packet Sniffer in C 🕵️‍♂️

A simple **network packet sniffer** written in **C** using `libpcap`. It captures packets from a specified network interface and extracts details like **IP addresses, protocols (TCP, UDP, ICMP), and ports**.

## 🚀 Features
- Captures **TCP, UDP, and ICMP** packets.
- Extracts **source/destination IPs, ports, and TTL**.
- Works on **Linux/macOS**.
- Uses **libpcap** for packet capture.

## 🛠 Installation
### 📌 Install Dependencies
#### **Ubuntu/Debian**
```bash
sudo apt update && sudo apt install libpcap-dev
Arch Linux
bash
Copy
Edit
sudo pacman -S libpcap
macOS (Homebrew)
bash
Copy
Edit
brew install libpcap
🔧 Compile
bash
Copy
Edit
gcc -o packet_sniffer sniff.c -lpcap
🏃‍♂️ Running the Sniffer
bash
Copy
Edit
sudo ./packet_sniffer <network_interface>
Example:

bash
Copy
Edit
sudo ./packet_sniffer eth0
⏹ Stopping the Sniffer
Press Ctrl + C.

## **📌 Author**
📌 Created by **Parth Dabgar**  
📧 Contact: dabgarparth12@gmail.com  

---




