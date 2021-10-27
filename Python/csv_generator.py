import os, sys, math, io
import numpy as np
import pandas as pd
import multiprocessing as mp
import bson
import struct
import matplotlib.pyplot as plt
import keras
import tensorflow as tf
from collections import defaultdict
from tqdm import *
from subprocess import check_output
from keras.preprocessing.image import load_img, img_to_array

# Input data files are available in the "../input/" directory.
# For example, running this (by clicking run or pressing Shift+Enter) will list the files in the input directory
# print(check_output(["ls", "./data"]).decode("utf8"))


data_dir = "./data/"
train_bson_path = os.path.join(data_dir, "train.bson")
num_train_products = 7069896

# train_bson_path = os.path.join(data_dir, "train_example.bson")
# num_train_products = 82

test_bson_path = os.path.join(data_dir, "test.bson")
num_test_products = 1768182


####
# categories_path = os.path.join(data_dir, "category_names.csv")
# categories_df = pd.read_csv(categories_path, index_col="category_id")
#
# # Maps the category_id to an integer index. This is what we'll use to
# # one-hot encode the labels.
# categories_df["category_idx"] = pd.Series(range(len(categories_df)), index=categories_df.index)
#
# categories_df.to_csv("categories.csv")
# categories_df.head()
#
# def make_category_tables():
#     cat2idx = {}
#     idx2cat = {}
#     for ir in categories_df.itertuples():
#         category_id = ir[0]
#         category_idx = ir[4]
#         cat2idx[category_id] = category_idx
#         idx2cat[category_idx] = category_id
#     return cat2idx, idx2cat
#
# cat2idx, idx2cat = make_category_tables()
#####


def read_bson(bson_path, num_records, with_categories):
    rows = {}
    with open(bson_path, "rb") as f, tqdm(total=num_records) as pbar:
        offset = 0
        index = 0
        while True:
            item_length_bytes = f.read(4)
            if len(item_length_bytes) == 0:
                break

            length = struct.unpack("<i", item_length_bytes)[0]

            f.seek(offset)
            item_data = f.read(length)
            assert len(item_data) == length

            item = bson.BSON.decode(item_data)
            product_id = item["_id"]
            num_imgs = len(item["imgs"])

            for i in range(num_imgs):
                image_id = str(product_id)+'-'+str(i)
                row = [image_id]
                if with_categories:
                    row += [item["category_id"]]
                rows[index] = row
                index += 1

            offset += length
            f.seek(offset)
            pbar.update()

    columns = ["image_id"]
    if with_categories:
        columns += ["category_id"]

    df = pd.DataFrame.from_dict(rows, orient="index")
    df.index.name = "index"
    df.columns = columns
    df.sort_index(inplace=True)
    return df

train_offsets_df = read_bson(test_bson_path, num_records=num_test_products, with_categories=False)
train_offsets_df.to_csv("./data/test_data.csv")