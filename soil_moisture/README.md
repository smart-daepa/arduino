# 🚿 토양 수분 감지 및 워터 펌프 - 김건우

## 목표 사항
**대파의 적정 습도 - 40% ~ 70%**

-> 화분의 토양 습도가 40% ~ 70%를 유지하도록 워터펌프가 작동해야 함

## 토양 수분 감지 센서 스펙
<table border="1">
  <tr>
   <th colspan=5>
     토양 수분 감지 센서 특징
   </th>
  </tr>
  <tr>
    <th>제품명</th>
    <th>특징</th>
    <th>입력 전압</th>
    <th>출력 값</th>
    <th>핀 배치</th>
  </tr>
  <tr>
    <td rowspan="3">YL-69</td>
    <td>아날로그 인터페이스</td>
    <td>3.3V ~ 5V</td>
    <td>마른 땅: 600 ~ 1000<br>젖은 땅: 370 ~ 600<br>물: 0 ~ 370</td>
    <td>A0: 아날로그 핀<br>D0: 디지털 핀<br>VCC: 전원 공급<br>GND: 접지</td>
  </tr>
</table>

## 아두이노 연결도
![soil_Sketch_bb](https://github.com/smart-daepa/arduino/assets/120733105/cdb0a18c-e46f-484d-a7f9-ec569b64aea4)

