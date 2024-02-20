import recuests as rec

data = rec.get("http://api.ipify.org/")
print(data.body)