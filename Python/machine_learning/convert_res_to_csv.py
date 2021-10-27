import pandas as pd
from Utils import *

org_test_csv_path = "./data/test.csv"
org_test_csv = pd.read_csv(org_test_csv_path)
internal_images_ids = list(org_test_csv['image_id'])

res_path = "./test_res/resnet_test_TTA.res"
res = []
with open(res_path) as f:
    res = f.readlines()

res = res[1:] # ignore head line
product_to_pesudo_label_map = {}
for line in res:
    splitted = line.strip().split(",")

    if splitted[0] in product_to_pesudo_label_map:
        print "wrong!"
        exit(0)
    else:
        product_to_pesudo_label_map[splitted[0]] = splitted[1]

csv_output = "index,image_id,category_id\n"
index = 0
for internal_image_id in internal_images_ids:
    product_id = imageid_to_productid(internal_image_id)
    pesudo_label = product_to_pesudo_label_map[product_id]
    csv_output += str(index) + "," + internal_image_id + "," + str(pesudo_label) + "\n"
    index += 1

output_csv_path = "data/test_pesudo_labeled.csv"
with open(output_csv_path, 'w') as f:
  f.write(csv_output)
