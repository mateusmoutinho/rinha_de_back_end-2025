DEPS = {
    {url = "https://github.com/OUIsolutions/DoTheWorld/releases/download/10.2.0/doTheWorldOne.c",save_as = "doTheWorldOne.c"},
    {url = "https://github.com/OUIsolutions/CWebStudio/releases/download/4.1.0/CWebStudioOne.c", save_as = "CWebStudioOne.c"},
    {url = "https://github.com/OUIsolutions/BearHttpsClient/releases/download/0.4.1/BearHttpsClientOne.c", save_as = "BearHttpsClientOne.c"},
    {url = "https://github.com/OUIsolutions/C-argv-parser/releases/download/0.0.2/CArgvParseOne.c", save_as = "CArgvParseOne.c"},
}


-- Downloads once, then reuses the result!
local cached_get_webpage = darwin.dtw.create_cache_function({
    expiration = 300,  -- 5 minutes
    cache_dir = "./web_cache/",
    cache_name = "webpage",  -- Added cache_name
    callback = function(url)
        darwin.dtw.remove_any("temp")
        os.execute("curl -L " .. url .. " -o temp")
        local content =  darwin.dtw.load_file("temp")
        darwin.dtw.remove_any("temp")
        return content
    end
})

for i=1,#DEPS do
    local dep = DEPS[i]
    local content = cached_get_webpage(dep.url)
    darwin.dtw.write_file("dependencies/" .. dep.save_as, content)
end

darwin.silverchain.generate({
    src = "src",
    project_short_cut = "RINHA_DE_BACK_END",
    tags = { 
        "dep",
        "macros",
        "types",
        "consts",
        "fdeclare",
        'globals',
        "fdefine",
}})

local final = darwin.camalgamator.generate_amalgamation("src/main.c")
darwin.dtw.write_file("rinha.c", final)