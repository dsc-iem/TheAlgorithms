import bson
import numpy as np
import pandas as pd
import os
from tqdm import *


out_folder = '../output/test'

# Create output folder
if not os.path.exists(out_folder):
    os.makedirs(out_folder)


# Create categories folders
#categories = pd.read_csv('./data/category_names.csv', index_col='category_id')


# for category in categories.index:
#     if not os.path.exists(os.path.join(out_folder, str(category))):
#         os.mkdir(os.path.join(out_folder, str(category)))

num_products = 1768182  # 7069896 for train and 1768182 for test

with open('./data/test.bson', 'rb') as fbson:
    data = bson.decode_file_iter(fbson)

    for c, d in tqdm(enumerate(data)):
        #category = d['category_id']
        _id = d['_id']
        for e, pic in enumerate(d['imgs']):
            #fname = os.path.join(out_folder, str(category), '{}-{}.jpg'.format(_id, e))
            fname = os.path.join(out_folder, '{}-{}.jpg'.format(_id, e))
            with open(fname, 'wb') as f:
                f.write(pic['picture'])
