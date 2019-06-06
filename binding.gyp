{  
    "targets":[  
        {  
            "target_name":"rpi-pixels",
            "sources":[  
                "src/cpp/addon.cpp"
            ],
            "include_dirs":[  
                "<!(node -e \"require('nan')\")"
            ],
            "ldflags":[  
                "-lrt"
            ],
			"cflags"      : ["-Wall -O3 -g" ],
			"cflags!"     : ["-Wno-unused-parameter", "-Wextra", "-fno-omit-frame-pointer", "-std=gnu++0x", "-fno-exceptions", "-fno-rtti" ],

			"cflags_cc"   : ["-Wall -g -fno-strict-aliasing -O2 -pthread"],
			"cflags_cc!"  : ["-Wno-unused-parameter", "-Wextra", "-fno-omit-frame-pointer", "-fno-exceptions", "-fno-rtti" ],
        }
    ]
}