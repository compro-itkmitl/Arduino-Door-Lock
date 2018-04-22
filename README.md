# Arduino Door Lock Project

## วัตถุประสงค์ของโปรเจคของเรา:

    โปรเจคของเราจัดทำขึ้นเพื่อการประยุกต์ใช้ Arduino Board ในการทำการปลดล็อคประตูด้วยรหัสผ่านเพื่อให้เกิดความทันสมัย และมีความปลอดภัยในการล็อคประตูมากขึ้น
     
## Hardware ของโปรเจค Arduino Door Lock:

    1. Arduino Board UNO
    2. LCD (16*2)
    3. Servo Motor
    4. Breadboard
     
## Function ของโปรเจค Arduino Door Lock:

    1. Present Password: รหัสสำหรับใช้ปลดล็อค (ไม่หายไปแม้แหล่งจ่ายไฟขาดไป เพราะข้อมูลถูกเก็บไว้ใน ROM) สามารถเปลี่ยนได้โดยการใช้ Factory Password
    2. Factory Password: รหัสสำหรับใช้เปลี่ยน Present Password ในกรณีลืมรหัสผ่าน หรือต้องการเปลี่ยนรหัสผ่าน โดย Factory Password สามารถเปลี่ยนได้โดยการแก้ใน Code เท่านั้น
    3. Lock Password: เมื่อใส่รหัสผิดเกิน 3 ครั้งจะทำการล็อคไม่ให้ใส่พาสเวิร์ดเป็นเวลา 5 วินาที แล้วหากใส่รหัสผิดอีก 3 ครั้งจะทำการล็อคอีกครั้งแต่เพิ่มระยะเวลาการล็อคอีก 1 วินาที

## Coding:

    1. ก่อน Compile และติดตั้ง Arduino Board กำหนด Present Password ในส่วนของ Code
    2. กำหนด Factory Password ในส่วนของ Code (ข้อควรระวัง: กรุณาตั้งค่า Factory Password ให้จำง่ายที่สุด และ/หรือ บันทึก Factory Password ไว้เผื่อใช้ในกรณีฉุกเฉิน)
     
## ทำไมต้องมี Password 2 ชุดในเมื่อ Password ชุดเดียวก็เพียงพอสำหรับการปลดล็อค ?? :

    เหตุการณ์สมมติ 1.1: นาย A ใช้ Arduino Door Lock กับตู้เซฟ แต่ว่านาย B เห็นและจำรหัสผ่านในการปลดล็อคได้ Code นาย A ไม่มี Factory Password นาย A จำเป็นต้อง Compile Code ชุดใหม่เพื่อเปลี่ยนรหัสผ่าน
    เหตุการณ์สมมติ 1.2: นาย A ใช้ Arduino Door Lock กับตู้เซฟ แต่ว่านาย B เห็นและจำรหัสผ่านในการปลดล็อคได้ Code นาย A มี Factory Password จึงใช้ Factory Password เปลี่ยนรหัสผ่านเป็นชุดใหม่
    เพราะ ในบางสถานการณ์เราจำเป็นต้องเปลี่ยนโค้ดเพื่อความปลอดภัย หรือเหตุการณ์ฉุกเฉินเช่นจำรหัสผ่านไม่ได้ รหัส Factory Password จึงมีเพื่อเป็นการป้องกันชั้นที่ 2 และลดความยุ่งยากในการเปลี่ยนรหัส
     
## Members:

    60070064     Pittawas     Choochuer
    60070066     Pimlapat     Yoouthong
    60070080     Ratana       Chumpasa

## Faculty of Information Technology
### King Mongkut's Institute of Technology Ladkrabang
