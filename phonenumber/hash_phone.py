participant = ["marina", "josipa", "nikola", "vinko", "filipa"]
completion = ["josipa", "filipa", "marina", "nikola"]
participant.sort()
completion.sort()
for n in range(len(completion)) :
    if participant[n] != completion[n] :
        participant[n]
print(participant[-1])


