package urlshort

import (
	"net/http"

	"gopkg.in/yaml.v2"
)

// MapHandler will return an http.HandlerFunc (which also
// implements http.Handler) that will attempt to map any
// paths (keys in the map) to their corresponding URL (values
// that each key in the map points to, in string format).
// If the path is not provided in the map, then the fallback
// http.Handler will be called instead.
func MapHandler(pathsToUrls map[string]string, fallback http.Handler) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		if v, ok := pathsToUrls[r.URL.String()]; ok {
			http.Redirect(w, r, v, http.StatusSeeOther)
		} else {
			fallback.ServeHTTP(w, r)
		}
	}
}

// YAMLHandler will parse the provided YAML and then return
// an http.HandlerFunc (which also implements http.Handler)
// that will attempt to map any paths to their corresponding
// URL. If the path is not provided in the YAML, then the
// fallback http.Handler will be called instead.
//
// YAML is expected to be in the format:
//
//     - path: /some-path
//       url: https://www.some-url.com/demo
//
// The only errors that can be returned all related to having
// invalid YAML data.
//
// See MapHandler to create a similar http.HandlerFunc via
// a mapping of paths to urls.
func YAMLHandler(yml []byte, fallback http.Handler) (http.HandlerFunc, error) {
	parsedYaml, err := parseYaml(yml)
	if err != nil {
		return nil, err
	}

	pathsToUrls := buildMap(parsedYaml)
	return MapHandler(pathsToUrls, fallback), nil
}

type URLMap struct {
	Path string
	Url  string
}

func buildMap(parsedYaml []URLMap) map[string]string {
	m := make(map[string]string)
	for _, um := range parsedYaml {
		m[um.Path] = um.Url
	}

	return m
}

func parseYaml(yml []byte) ([]URLMap, error) {
	var urls []URLMap
	err := yaml.Unmarshal(yml, &urls)
	if err != nil {
		return nil, err
	}

	return urls, nil
}
