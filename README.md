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

## **📌 Author**
📌 Created by **Parth Dabgar**  
📧 Contact: dabgarparth12@gmail.com  

