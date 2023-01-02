# dss
<h1>Distributed Systems Server</h1>
<p>The objective for this project is to create a way of building websites
without having to use multiple tools and programming languages, just C++.</p>

<p>Another goal of this project is to allow the distribution of work within a
computer cluster to be distributed efficiently.</p>

the objective for this project is to create a way of building websites
without having to use multiple tools and programming languages, just C++.

this project will be split into classes.

Here is a rough outline of how the server will work.

	// setup an actual file descriptor
	socket()
	bind()
	listen()

	// accept clients
	accept() // run in a loop and give the new file descriptor to a function

	read()
	parse
	determine program flow
	form a response, or terminate connection or call read() again.
	write()
	close() or go to the read step again.
	
Everything done in between read and write will be up to the actual
web designers. That is where they will have the website features.

Everything described above, except for determining program flow and
forming a response can be integrated as a standard portion of the project.

It will be up to the website designers to learn how the standard features
are used, which should be made easy due to good quality documentation.

The website designers should only need to worry about the actual task
of designing the features of the website, not about the lower level
aspects. The low level operation should be abstracted away, so the web
designers can focus on making a good user experience.


Advantages of aggregation:
Having a standalone process which can be started at will can allow
the website to perform more efficiently and faster. The normal operation
of a website is to use something like PHP to provide features. The
extentions have overhead associated, such as forking processes and task
creation and destruction. If everything is compiled into a standalone
process, then it will allow the C++ compiler to work its magic, and
make the process faster and more efficient.

Why C++ was chosen:
Currently, as of January 2023, the C++ compilers such as clang and g++
are able to turn high level code into the most efficient assembly code.
These compilers are some of the most complex software programs currently
employed, and they do incredibly well in their task.

C++ is a high level language that allows for low level manipulation,
and more importantly, allows for those low level procedures to be easily
abstracted away and turned into efficient assembly code. C++ has many features,
many of which are never used by developers, however when they are used, they
can be guaranteed to generate the most efficient assembly possible.
