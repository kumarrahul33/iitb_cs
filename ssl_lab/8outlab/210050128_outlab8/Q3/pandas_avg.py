import pandas as pd

def read_data(file_name):
    r"""
        This function reads the contents from the file,
        specified by the file_name into a pandas DataFrame.
    """
    df = pd.read_csv(file_name)
    return df

def compute_avg(data_frame):
    r"""
        This function takes in a DataFrame and returns another 
        DataFrame with the computed averages
    """
    data = {
        'programme':["BTech","MS","PhD"],
        'cgpa':[
        data_frame.loc[data_frame['programme'] == "BTech"].cgpa.mean(),
        data_frame.loc[data_frame['programme'] == "MS"].cgpa.mean(),
        data_frame.loc[data_frame['programme'] == "PhD"].cgpa.mean()
        ]
    }
    df = pd.DataFrame(data) 
    return df

if __name__ == '__main__':
    df = read_data('example_input.csv')
    print('\n=============INPUT DF=============\n')
    print(df)
    print('\n=============EXPECTED OUTPUT=============\n')
    print(compute_avg(df))