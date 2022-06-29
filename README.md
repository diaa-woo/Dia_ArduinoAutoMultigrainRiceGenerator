# Dia_ArduinoAutoMultigrainRiceGenerator

> **Note**   
> 상품 홍보하는게 아닙니다! ㅋㅋ

## 프로젝트 개요

만든 일자: 2021.08 ~ 2021.12   
만들었던 장소: <a href="http://www.bssm.hs.kr">부산소프트웨어마이스터고등학교</a>

소개: 곡류 세 종류를 사용자가 원하는 만큼 조합할 수 있게 해주는 장치

사용 부품: <a href="https://store.arduino.cc/products/arduino-nano">아두이노 나노</a> **3개**, <a href="https://www.devicemart.co.kr/goods/view?no=13843">스텝 모터</a>, <a href="https://www.devicemart.co.kr/goods/view?no=1327614">스텝 모터 드라이버(TB6560)</a>, <a href="https://www.devicemart.co.kr/goods/view?no=1313388">서보 모터</a>, <a href="https://www.devicemart.co.kr/goods/view?no=12500005">16*2 LCD</a>, <a href="https://www.devicemart.co.kr/goods/view?no=10916349">포토 인터럽터</a>

팀원과 역할: <a href="https://github.com/diadntjr">diadntjr</a>(황우석, 팀장, 메인), <a href="https://github.com/KEHyeon">KEHyean</a>(김태현, 서보모터 제어), <a href="https://github.com/sookyoungwoo">sookyoungwoo</a>(우수경, 기록 및 디자인), <a href="https://github.com/Lovingcats">lovingcats</a>(조용제, 스크류 모터 제어)   
   
Special Thanks: <a href="https://github.com/sjwoong1010">sjwoong1010</a>

## 프로젝트 소개

__"잡곡 비율을 내 맘대로 조절할 수 있어요!"__
   
잡곡밥을 주로 먹는 집에서는, 보통 쌀통에다가 흰쌀, 귀리, 검은콩 등등 여러 곡류들을 한군데 모아서 난잡하게 섞고 이를 퍼가며 밥을 지어가고 있었습니다. 이 경우 한번 섞으면 편하게 뜨고 플 수 있지만, 정확한 비율을 재기 어려워 가끔 한 곡류가 불필요하게 많이 섞여져서 밥을 짓는 경우도 있습니다. 이에 저희는 여러 곡류들을 따로 분류한 뒤, 스크류 레일을 이용해 통을 이동시켜 여러 곡류를 섞어줄 수 있게 해주었습니다.   
    
__"내 마음대로 비율을 조절할 수 있어요!"__   
 
매일매일 같은 비율의 잡곡밥을 먹기는 질릴 것입니다. 이에 여러 사용자 모드를 두고, 각 모드마다 다른 설정값을 두어, 각각 다른 비율의 곡류가 나올 수 있게 해두었습니다. 사용자 직접 제어도 가능합니다.   
  
__"직접 제어할 수 있는 인터페이스가 있어요!"__   
   
LED 등을 이용하여 직관적으로 확인할 수 있는 방법은 많지만, 사용자가 직접 알 수 있게 LCD로 인터페이스를 구현하였습니다. 버튼을 통해 여러 모드들(비율 모드, 직접 제어 모드 등)로 이동할 수 있으며, 비율 모드로 곡류를 배출하는 경우는 직접 비율을 확인할 수 있고, 현재 동작 모드를 확인할 수 있어 더 활발한 사용이 가능합니다!
 
__사진과 설명들__


 
 ## 프로젝트 과정

  
