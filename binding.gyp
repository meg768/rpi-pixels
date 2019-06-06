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
            "cflags":[  
                "-Wall -O3 -g -fexceptions"
            ]
        }
    ]
}