# Qt WebEngine example
This is a usage example for some [Qt WebEngine](https://doc.qt.io/qt-6/qtwebengine-overview.html) features.
This is also part of the post “Integrare contenuti web in un'applicazione desktop Qt/C++”.

## Features
We can group features in:
- Qt app
  - Allows to either request or return a book to the library
  - Receives and shows incoming messages from the  library
- Library web page
  - Keeps the book list updated, according to loan requests
  - Shows the loans and returns log
  - Sends messages to Qt app

So, Qt and the web page can communicate in a bidirectional way.


![qt_web_example_screenshot](https://github.com/develer-staff/qt_web_example/assets/38531312/aa4f0915-0249-43b2-895f-a6d6e6be0615)

The above screenshot shows the running application.

Inside “Library web view” pane there's the HTML/JS library page. As you can see, we can have a uniform UI.

# Inspect a QWebEngineView
To debug a QWebEngineView you can use developer tools:
- Go to _Projects_ tab on the left > _Build & Run_ section > _Run_ > _Environment_
- Add a new variable key: `QTWEBENGINE_CHROMIUM_FLAGS` and value: `--remote-debugging-port=<port_number>`
- Run the Qt app
- Open your browser and go to `http://localhost:<port_number>/`
- Choose the page you want to inspect

See [Qt WebEngine Debugging and Profiling](https://doc.qt.io/qt-6/qtwebengine-debugging.html) for more information.
