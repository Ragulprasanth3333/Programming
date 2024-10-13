import Newsautomation


def test_get_articles_by_category():
    articles = Newsautomation.get_articles_by_category('technology')
    assert len(articles) > 0
    assert all(isinstance(article, dict) for article in articles)
    assert all('title' in article and 'url' in article for article in articles)

def test_get_sources_by_category():
    sources = Newsautomation.get_sources_by_category('technology')
    assert len(sources) > 0
    assert all(isinstance(source, dict) for source in sources)
    assert all('name' in source and 'url' in source for source in sources)

def test_get_article_count_by_category():
    article_count = Newsautomation.get_article_count_by_category('technology')
    assert isinstance(article_count, int)
    assert article_count >= 0

