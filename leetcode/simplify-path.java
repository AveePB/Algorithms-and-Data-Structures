class Solution {
    public int backtracking(String[] directories, String[] absolute, int idx, int ptr) {
        if(idx >= directories.length) return ptr;
        if(ptr < 0) ptr = 0;

        absolute[ptr++] = directories[idx];
        if(directories[idx].equals("..")) ptr -= 2;
        else if(directories[idx].equals(".")) ptr--;

        return backtracking(directories, absolute, idx+1, ptr);
    }

    public String simplifyPath(String path) {
        StringBuilder sb = new StringBuilder();
        sb.append(path.charAt(0));

        for(int i=1; i<path.length(); i++) {
            if(path.charAt(i-1) == '/' && path.charAt(i) == '/')
                continue;
            sb.append(path.charAt(i));
        }

        String[] directories = sb.toString().split("/");
        String[] absolute = new String[500];

        int n = backtracking(directories, absolute, 1, 0);
        if(n <= 0) return "/";

        StringBuilder ans = new StringBuilder();
        for(int i=0; i<n; i++) ans.append('/').append(absolute[i]);

        return ans.toString();
    }
}
