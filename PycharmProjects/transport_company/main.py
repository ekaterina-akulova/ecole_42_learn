import dash
import pandas as pd
import plotly.express as px
from dash import dcc
from dash import html
from dash.dependencies import Input, Output

passanger_traffic_data = pd.read_excel('../transport_company/Пассажиропоток.xlsx')
traffic_data = pd.read_excel('../transport_company/Поток.xlsx')
passanger_traffic_data = passanger_traffic_data.dropna()
traffic_data = traffic_data.dropna()
#print(passanger_traffic_data.head(7))
#print(traffic_data.head(7))
#print(passanger_traffic_data.values)
#print(passanger_traffic_data.dtypes.value_counts())
#print(traffic_data.dtypes.value_counts())
#print(passanger_traffic_data.info)
#print(traffic_data.info)
#print(passanger_traffic_data.columns)
#print(traffic_data.columns)
voz_pass = []
voz_tr = []
ind = 0
voznagrazhdenie = []
percent = 0
plus = 0
for i, row in passanger_traffic_data.iterrows():
    voz_pass.append(row['Кол-во поездок'] * row['Сумма поездок'])
    if row['Тип ТК'].find("ПБ") != -1:
        percent = 6
    elif row['Тип ТК'].find("ЭК") != -1:
        percent = 7
    elif row['Тип ТК'].find("БК") != -1:
        percent = 7.5
    elif row['Тип ТК'].find("НАЛ") != -1:
        percent = 2
    else:
        print('Unexpected error')
    percent = percent / 100
    voz_pass[ind] = int(voz_pass[ind])
    voz_without_percent = float(voz_pass[ind]) * percent
    voznagrazhdenie.append((voz_pass[ind]) - voz_without_percent)
   # print(voznagrazhdenie[ind])
    ind += 1


for index, r in traffic_data.iterrows():
    if r['Вместимость'].find("СВ") != -1:
        plus = 40
    elif r['Вместимость'].find("БВ") != -1:
        plus = 55
    else:
        print('Unexpected error')
    voz_tr.append(r['ТР факт'] * plus)
    print("print voz tr ind", voz_tr[ind])




