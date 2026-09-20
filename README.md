# PFD Test

## What is PFD?
주로 항공기에 탑재되는 소프트웨어인 PFD(Primary Flight Display) 주행장치 지시계는 항공기의 속도, 고도, 자세, 방위 등 비행에 꼭 필요한 핵심 정보를 하나의 화면에 종합적으로 보여주는 소프트웨어입니다.

## Background
어느날, 항공 전자 시스템에 대해 더 탐구하던 중, F-35 전투기의 조종석에 탑재되는 LAD(대형 영역 디스플레이)를 보며, "아 저거 멋지다" 라고 생각하게 되었고, 그 첫번째 단계인 PFD를 한번 구현해보자는 생각이 들어서, 이렇게 제작하게 되었습니다.

## Overview
이런 PFD를 구현하기 위해 사용한 마이크로컨트롤러는 아두이노 UNO, 거기에 자이로/가속도 센서인 MPU5060을 결선하여 기반을 잡았으며, 
그 다음으로 컴퓨터 내부로 들어오는 특정 데이터를 시각화 해주는 프로세싱(Processing)이라는 공개 소프트웨어를 사용해서 PFD를 구현했습니다.

<p align="center">
  <img src="https://github.com/MiruHeon/Normal-Project/blob/main/pfd.png?raw=true" alt="PFD" width="500" />
</p>

## Architecture
```
MPU6050 기울기 데이터 수집 및 전송(아두이노)
      ↓
기울기 데이터 분할(x,y)
      ↓
데이터 시각화(프로세싱)
```

## Wiring Diagram
<p align="center">
  <img src="https://github.com/MiruHeon/Normal-Project/blob/main/%ED%9A%8C%EB%A1%9C%EB%8F%84.png?raw=true" alt="배선도" width="600" />
</p>

## Core Features
### Two-dimensional structure
이 작품에선, Roll, Pitch의 시각화만 구현되고 방위각(Yaw)의 시각화는 없이 설계되었습니다.
따라서, 기울기 데이터 본연의 변화량만 화면에 왜곡 없이 명확하게 전달할 수 있습니다.

## 개발 팀원 소개
| 류용헌 |
|:------:|
| <img src="https://github.com/MiruHeon/Normal-Project/blob/main/profile.png?raw=true" alt="류용헌" width="150"> |
| PL |

