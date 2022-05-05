int graph[][]
vector<int> path

bool promising(int i){
    //v번 진행했으나 다시 첫 지점으로 돌아가는 간선이 없는 경우 false
    if(i == v && !graph[path[v]][path[1]]) return false;
    //간선이 없는 경우 false
    else if(i > 1 && !graph[path[i-1]][path[i]]) return false;
    //이미 방문했던 곳이면 false
    else {
        for(int j = 1; j < i; j++){
            if(path[i] == path[j]) return false;
        }
    }

    //나머지 경우는 true
    return true;
}

//i : 마지막 방문한 index
solve(int i){
    if(!promising(i)) return;

    //무사히 v번 진행했으면
    if(i == v) {
        //결과출력
    }
    //아직 v번 진행하지 못했으면 일단 다 재귀시켜본다(간선이 없는 경우도 promising에서 거른다)
    else{
        for(int j = 2; j <= v; j++){
            path[i+1] = j;
            solve(i+1);
        }
    }
}