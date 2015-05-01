```
int main() {
  HttpServer http_server();

  FrontendApp frontend_app();
  AdminApp admin_app();
  http_server.map("/admin", admin_app);
  http_server.map("/", frontend_app);

  http_server.bind(80);
}

class FrontendApp : public RoutesApp {
  FrontendApp() {
    map("/about", &about)
  }

  future<Response> about(Request request) { ... }
};

class SomeResponse : public HttpOkResponse, public HtmlResponse {
};

SomeResponse response;
response.html = SomeHtmlDocument();
return new promise<Response>(response);
```
