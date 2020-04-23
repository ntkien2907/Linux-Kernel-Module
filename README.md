# CHARACTER DEVICE TẠO SỐ NGẪU NHIÊN

##### Hướng dẫn sử dụng #####
* B1: Mở terminal ở thư mục chưa các file hiện tại.
* B2: Gõ lệnh **make**. Module được tạo ra.
* B3: Để đưa module vô kernel, gõ lệnh **sudo insmod random_driver.ko**
* B4: Gõ lệnh **dmesg** để kiểm tra driver có **số major** là bao nhiêu.
* B5: Tạo device file để quản lí driver vừa tạo.
Gõ lệnh: **sudo mknod /dev/random_dev c <số major> 0**
* B6: Gõ **./run** để chạy.

* B7: Để gỡ module ra khỏi kernel, gõ **sudo rmmod random_driver**
* B8: Xóa device file đã tạo ở B5, gõ **sudo rm /dev/random_dev**

##### Một số lệnh kiểm tra #####
* Danh sách module trên kernel -> **lsmod**
* Danh sách device file -> **ls -la /dev**
* Danh sách driver hiện có -> **cat /proc/devices**
