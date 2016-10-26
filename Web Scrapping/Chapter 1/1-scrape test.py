from urllib.request import urlopen

url = "http://pythonscraping.com/pages/page1.html"
html = urlopen(url)
print(html.read())