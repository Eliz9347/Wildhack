import numpy as np
import pandas as pd

print("Please insert path to search_history")
# G:\Learning_2021\WildHack\search_history.csv.gz
search_history_path = input()
print("Please insert new file name")
# ParsedSearchHistory.csv
new_file_name = input()

df = pd.read_csv(search_history_path, sep ='\t')
df['wbuser_id'] = df['wbuser_id'].astype("string")
df= df.sort_values(by=['wbuser_id'])

df["new_time"] = np.nan
df["count_uq"] = np.nan
df['time'] = pd.to_datetime(df['time'])
df['UQ'] = df['UQ'].astype("string")
index_ = 0
# current_row = df.iloc[index_]
# datetime.strptime(df[1]['time'], "%H:%M:%S")
count_uq = 0
# t =uq_first_time -uq_first_time

for index, row in df.iterrows():
    if df.iloc[index,2] == df.iloc[index_,2]: 
        uq_time =  df.iloc[index,6] - df.iloc[index_,6]
        count_uq += 1
    else:
        df.iloc[index_,7] = uq_time
        df.iloc[index_,8] = count_uq
        count_uq = 1
        uq_time = 0
        index_ = index

df = df.drop(df[df.count_uq.isnull()].index)
df.to_csv(new_file_name, sep='\t', encoding='utf-8')