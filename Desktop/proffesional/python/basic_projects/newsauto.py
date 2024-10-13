import requests

API_KEY = "e3249174c0974f99a88bc8465e96f30a"

URL = 'https://newsapi.org/v2/top-headlines?'

def get_articles_by_category(category):
    query_parameters = {
        "category": category,
        "sortBy": "top",
        "country": "gb",
        "apiKey": API_KEY
    }
    return _get_articles(query_parameters)

def get_sources_by_category(category):
    url = 'https://newsapi.org/v2/top-headlines/sources'
    query_parameters = {
        "category": category,
        "language": "en",
        "apiKey": API_KEY
    }

    response = requests.get(url, params=query_parameters)

    sources = response.json().get('sources', [])
    
    return sources

def get_article_count_by_category(category):
    articles = get_articles_by_category(category)
    return len(articles)

def _get_articles(params):
    response = requests.get(URL, params=params)

    if response.status_code == 200:
        articles = response.json().get('articles', [])
        return articles
    else:
        print(f"Error: {response.json().get('message', 'Unknown error')}")
        return []

def main():
    category = input("Enter category: ")
    articles = get_articles_by_category(category)
    if articles:
        for article in articles:
            print(article['title'])
            print(article['url'])
            print('')
        print(f"Successfully retrieved top {category} headlines")
    else:
        print("Failed to retrieve news articles.")

if __name__ == "__main__":
    main()
